#include "damage_detection.h"
#include <qdebug.h>

//Algorithm to detect damaged areas in sea cages-------------------------------------------//
cv::Mat Hole_detection_algo(cv::Mat input_img)
{
    cv::Mat output_img; //image with detected holes
    if((!input_img.empty())&& (input_img.channels()==1))
    {
        QList<int> region_size_list;
        QList<cv::Vec6i> region_list;//[uppermost,furthest down,leftmost,rightmost,area,0]
        cv::Vec6i region;
        input_img.copyTo(output_img);

        int area;
        int color = 50;

        for(int j = 1;j<output_img.rows-1;j++)
        {
            uchar* data_row = output_img.ptr<uchar>(j);
            for(int i =1;i<output_img.cols-1;i++)
            {
                if(data_row[i] == 0)
                {
                    region = Region_Growing(output_img,j,i,color);
                    color = color + 50;
                    if(color>200)
                    {
                        color = 50;
                    }
                    area = region[4];

                    //printed_region_size_list.append(area);
                    if(area>20)//to prevent small pixel areas to count
                    {
                        region_size_list.append(area);
                        region_list.append(region);
                    }
                }
            }
        }

        //finds the most likely average area size
        if(region_size_list.size()>0)
        {
            qSort(region_size_list.begin(),region_size_list.end());

            int nominal_val = 0;
            int nominal_val_occurrences = 0;
            int current_nominal_val_occurrences = 0;
            for(int i = 0;i<region_size_list.last();i++)
            {
                if((i>4)&&((i+5)<region_size_list.size()))
                {
                    nominal_val_occurrences = 0;
                    for(int j = -5; j<10;j++ )
                    {
                        nominal_val_occurrences = nominal_val_occurrences + region_size_list.count(i+j);
                    }

                    if(nominal_val_occurrences>current_nominal_val_occurrences)
                    {
                        current_nominal_val_occurrences = nominal_val_occurrences;
                        nominal_val = i;

                    }

                }
            }
            //gives out the most occuring area value
            //qDebug() << "occurences:" << nominal_val_occurrences << "   for value:" << nominal_val;

            //the region size with most occurences is thought to be the nominal region size.
            //Since some of the region can span two or three masks without there beingh no damage
            //to the net region that are from 2 times to 4 times the size of the nominal size
            //is considered suspect regions and larger areas are considered holes.
            foreach(cv::Vec6i a ,region_list)//[uppermost,furthest down,leftmost,rightmost,area,0]
            {
                //drawing on image, light grey circle if big area and black if small area
                if(a(4) >= 5*nominal_val)
                {
                    cv::circle(output_img,cv::Point(a(2)+(a(3)-a(2))/2,a(0)+(a(1)-a(0))/2),(int)(a(1)-a(0))/2,200,5,8,0);
                }
                else if(a(4) >= 2.5*nominal_val)
                {
                    cv::circle(output_img,cv::Point(a(2)+(a(3)-a(2))/2,a(0)+(a(1)-a(0))/2),(int)(a(1)-a(0))/2,0,3,8,0);
                }
            }
        }
    }


    return output_img;
}
//---------------------------------------------------------------------------------------------//


//Grows region from a seed pixel, if the region contains pixels at the top AND bottom border---//
//or left AND right border the area is set to 0 to exclude the region from further processing--//
//This to eliminate false areas present during testing.----------------------------------------//
//---------------------------------------------------------------------------------------------//
cv::Vec6i Region_Growing(cv::Mat input_img,int x, int y, int color)
{
    int area = 1;
    QList<cv::Vec2i> growing_list;
    growing_list.append(cv::Vec2i(x,y));
    cv::Vec6i returned_param;//[uppermost,furthest down,leftmost,rightmost,area,0]
    returned_param[0] = x;
    returned_param[1] = x;
    returned_param[2] = y;
    returned_param[3] = y;
    returned_param[4] = area;
    returned_param[5] = 0;
    input_img.at<uchar>(x,y) = color;
    bool change = true;


    //grow region and keep the pixels that are leftmost rightmost and furthest down, pixelnumber not coordinate
    while(change)
    {
        change = false;
        foreach(cv::Vec2i a ,growing_list)
        {
            growing_list.removeFirst();//removes the pixel being examined

            if((a(0)>0) && (a(1)>0) && (a(0)<(input_img.rows-1)) && (a(1)<(input_img.cols-1)) ) //dont use mask on border pixels.
            {
                uchar* previous_row = input_img.ptr<uchar>(a(0)-1);
                uchar* current_row = input_img.ptr<uchar>(a(0));
                uchar* next_row = input_img.ptr<uchar>(a(0)+1);
                if(previous_row[a(1)]==0)
                {
                    change = true;
                    growing_list.append(cv::Vec2i(a(0)-1,a(1)));
                    area = area+1;
                    previous_row[a(1)] = color;
                    if(a(0)-1< returned_param[0])//checking topmost, should never come into this one
                    {
                        returned_param[0]=a(0)-1;
                    }
                }
                if(current_row[a(1)-1]==0)
                {
                    change = true;
                    growing_list.append(cv::Vec2i(a(0),a(1)-1));
                    area = area+1;
                    current_row[a(1)-1] = color;
                    if( (a(1)-1)<returned_param[2])//checking leftmost
                    {
                        returned_param[2]= a(1)-1;
                    }
                }
                if(current_row[a(1)+1]==0)
                {
                    change = true;
                    growing_list.append(cv::Vec2i(a(0),a(1)+1));
                    area = area+1;
                    current_row[a(1)+1] = color;
                    if( (a(1)+1)>returned_param[3])//checking rightmost
                    {
                        returned_param[3]= a(1)+1;
                    }
                }
                if(next_row[a(1)]==0)
                {
                    change = true;
                    growing_list.append(cv::Vec2i(a(0)+1,a(1)));
                    area = area+1;
                    next_row[a(1)] = color;
                    if(a(0)+1> returned_param[1])//checking lowest
                    {
                        returned_param[1]=a(0)+1;
                    }
                }
            }
        }
    }

    //testing to see if area crosses the screen, only to be used for videos from the field test
    //since the sea cage panels are smaller than the are filmed
    if(((returned_param[0]==0)&&(returned_param[1]==input_img.rows-1)) || ((returned_param[2]==0)&&(returned_param[3]==input_img.cols-1)))
    {
        returned_param[4] = 0;
    }
    else
    {
        returned_param[4]=area;
    }

    return returned_param;
}
//---------------------------------------------------------------------------------------------//
