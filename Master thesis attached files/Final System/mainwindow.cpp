#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setup window
    ui->setupUi(this);
    this->setWindowTitle(QString("System 2, v.0.1"));

    //initializing parameters.
    Local_Sobel_numberofSubImages = 1;
    Local_Sobel_hist_percentile = 70;
    Local_Sobel_dx = 1;
    Local_Sobel_dy = 1;
    Local_Sobel_kernel_size = 3;

    Dilation_iterations = 1;
    Gaussian_kernel_size = 1;

    Percentage_foreground_clean_net = -1;
    capture_clean_net = false;
    capture = false;

    mode = NO_MODE;
    PAUSE = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Processes the frame according to settings chosen
void MainWindow::process_frame(cv::Mat b4_tweak_input_image)
{
        cv::Mat input_image = tweak_video_frame(b4_tweak_input_image);//if input video needs to be cut


        cv::Mat color_space_image,Segmented_image,damage_detected_image;
        cv::Mat lab_image;

        //Converting to the Y color space from CIE XYZ
        color_space_image = custom_Y(input_image);

        //Using image enhancement methods chosen-----------------------------//

        //Smoothing image before segmentation
        if(ui->Gaussian_checkBox->isChecked() && !color_space_image.empty())
        {
            cv::GaussianBlur(color_space_image,color_space_image,cv::Size(Gaussian_kernel_size,Gaussian_kernel_size),0,0,cv::BORDER_DEFAULT);
        }
        //Light gradient equalization
        if((ui->Gradient_equalizer_checkBox->isChecked()) && (color_space_image.channels()==1))
        {
            color_space_image = Light_gradient_equalizer(color_space_image);
        }

        if(ui->Morphological_gradient_equalizer_checkBox->isChecked() && color_space_image.channels()==1)
        {
            color_space_image = Morpological_light_gradient_equalizer(color_space_image);

        }
        //Morphological contrast enhancement
        if(ui->Morphological_sharpen_checkBox->isChecked() && color_space_image.channels()==1)
        {
            color_space_image = Morpological_contrast_enhancement(color_space_image);
        }
        //--------------------------------------------------------------------------//


        //Using chosen Scharr with .... for growth detection or Sobel wirth histogram percentile --------------//

        if(ui->Growth_detection->isChecked())
        {
            Segmented_image = Local_Scharr(color_space_image,1,false,70,true,70,true,true,false,0.8,0.5);
        }
        else
        {
            Segmented_image = Local_Sobel(color_space_image,1,3,70,1,1,false,0.9,0.5);
        }


        //Using morphological dilation followed by opening--------------------------//
        if(!Segmented_image.empty())
        {
            if(ui->Dilation_checkBox->isChecked())
            {
                cv::Mat Seg_copy;
                Segmented_image.copyTo(Seg_copy);
                cv::dilate(Seg_copy,Segmented_image,cv::Mat(),cv::Point(-1,-1),Dilation_iterations,cv::BORDER_CONSTANT,cv::morphologyDefaultBorderValue());
            }
            //removing salt with opening
            cv::Mat Seg_copy2;
            Segmented_image.copyTo(Seg_copy2);
            cv::Mat element = cv::getStructuringElement(CV_SHAPE_ELLIPSE,cv::Size(5,5));
            cv::morphologyEx(Seg_copy2,Segmented_image,cv::MORPH_OPEN,element);

            //inverting image to remove pepper using opening, then inverting back
            Segmented_image.copyTo(Seg_copy2);
            uchar* Seg_copy_image_ptr = Seg_copy2.ptr<uchar>(0);
            for(int i = 0;i<Seg_copy2.cols*Seg_copy2.rows;i++)
            {
              Seg_copy_image_ptr[i] = 255-Seg_copy_image_ptr[i];
            }
            cv::morphologyEx(Seg_copy2,Segmented_image,cv::MORPH_OPEN,element);
            uchar* Seg_image_ptr = Segmented_image.ptr<uchar>(0);
            for(int i = 0;i<Segmented_image.cols*Segmented_image.rows;i++)
            {
              Seg_image_ptr[i] = 255-Seg_image_ptr[i];
            }
        }
        //--------------------------------------------------------------------------//

        //Using chosen program mode-------------------------------------------//
        switch(mode)
        {
        case NO_MODE:
            break;
        case HOLE_DETECTION:
            damage_detected_image = Hole_detection_algo(Segmented_image);
            break;
        case GROWTH_DETECTION:
            if((Percentage_foreground_clean_net > -1) && (!Segmented_image.empty()))
            {                
                int percentage_growth = Growth_Detection_algo(Percentage_foreground_clean_net,Segmented_image);
                ui->growth_plainText->appendPlainText(QString::number(percentage_growth) + QString("%"));
            }
            break;
        }
        //--------------------------------------------------------------------//

        display_frame(input_image,color_space_image,Segmented_image,damage_detected_image);
}



//Set capture to true to save image in dislpay frame function
void MainWindow::on_Capture_clicked()
{
    capture = true;
}

//Set program mode----------------------------------------------------//
void MainWindow::on_No_Mode_clicked()
{
    mode = NO_MODE;
}

void MainWindow::on_Hole_Detection_clicked()
{
    mode = HOLE_DETECTION;
}

void MainWindow::on_Growth_detection_clicked()
{
    mode = GROWTH_DETECTION;
}
//--------------------------------------------------------------------//



//From enhancement methods groupbox-----------------------------------//

void MainWindow::on_Dilation_horizontalSlider_valueChanged(int value)
{
    Dilation_iterations = value;
}

void MainWindow::on_Gaussian_horizontalSlider_valueChanged(int value)
{
    if(value % 2)
    {
        Gaussian_kernel_size = value;
        ui->Gaussian_lcdNumber->display(value);
    }
}
//--------------------------------------------------------------------//


//Capture clean net for Growth detection Program mode
void MainWindow::on_Capture_clean_net_pushButton_clicked()
{
    capture_clean_net = true;
}


//Processing chosen input source--------------------------------------//
void MainWindow::on_Webcam_source_radioButton_clicked()
{
    capWebcam.release();
    capWebcam.open(0);
    if(capWebcam.isOpened() == false)
    {
        ui->Total_time_spent->appendPlainText("error: Webcam not accessed succesfully");
        return;
    }
    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()),this,SLOT(runCamera()));
    tmrTimer->start(100);

}

void MainWindow::on_Image_source_radioButton_clicked()
{
    capWebcam.release();
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    image_from_file = cv::imread(fileName.toLatin1().data()) ;
    //change color channel ordering
    cv::cvtColor(image_from_file,image_from_file,CV_BGR2RGB);

    //rolling it like a video to get operations to work, first change color space to a valid one
    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()),this,SLOT(runImage()));
    tmrTimer->start(100);
}

void MainWindow::on_Video_source_radioButton_clicked()
{
    capWebcam.release();
    fileName = QFileDialog::getOpenFileName(this,tr("Open Video"),".",tr("Video Files (*.avi *.mp4 *.wmv)"));
    capWebcam.open(fileName.toLatin1().data());
    if(capWebcam.isOpened() == false)
    {
        ui->Total_time_spent->appendPlainText("error: Video not accessed succesfully");
        return;
    }

    video_file_FPS = capWebcam.get(CV_CAP_PROP_FPS);

    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()),this,SLOT(runVideo()));
    tmrTimer->start(100);
}
//--------------------------------------------------------------------//


//Run chosen input source---------------------------------------------//
void MainWindow::runCamera()
{
    if(PAUSE == false)
    {
        cv::Mat camera_image;
        capWebcam.read(camera_image);
        if(camera_image.empty()==true) return;

        double duration;
        duration = static_cast<double>(cv::getTickCount());

        //change color channel ordering
        cv::cvtColor(camera_image,camera_image,CV_BGR2RGB);

        MainWindow::process_frame(camera_image);

        //time measurment part
        duration = static_cast<double>(cv::getTickCount())-duration;
        duration /=cv::getTickFrequency();
        ui->Total_time_spent->appendPlainText(QString::number(duration) + QString("s"));
    }
}
void MainWindow::runImage()
{
    if(image_from_file.empty()==true) return;

    if(PAUSE == false)
    {
        double duration;
        duration = static_cast<double>(cv::getTickCount());

        MainWindow::process_frame(image_from_file);

        //time measurment part
        duration = static_cast<double>(cv::getTickCount())-duration;
        duration /=cv::getTickFrequency();
        ui->Total_time_spent->appendPlainText(QString::number(duration) + QString("s"));
    }
}
void MainWindow::runVideo()
{
    if(PAUSE == false)
    {
        double duration;
        duration = static_cast<double>(cv::getTickCount());

        cv::Mat video_frame;

        bool end_of_video = false;
        int frame_not_found = 0; //gives the system the chance to process videos missing frames
        while(end_of_video==false)
        {
            capWebcam.read(video_frame);

            if(!video_frame.empty())
            {
                cv::cvtColor(video_frame,video_frame,CV_BGR2RGB);
                MainWindow::process_frame(video_frame);
                end_of_video = true;
            }
            else
            {
                frame_not_found +=1;
            }

            if(frame_not_found >100)
            {
                capWebcam.release();
                capWebcam.open(fileName.toLatin1().data());
                if(capWebcam.isOpened() == false)
                {
                    ui->Total_time_spent->appendPlainText("error: Video not accessed succesfully");
                    return;
                }
                end_of_video = true;
            }
        }
        //time measurment part
        duration = static_cast<double>(cv::getTickCount())-duration;
        duration /=cv::getTickFrequency();
        ui->Total_time_spent->appendPlainText(QString::number(duration) + QString("s"));
    }
}
//--------------------------------------------------------------------//


//Pause and Reset buttons---------------------------------------------//
void MainWindow::on_actionPause_triggered()
{
    if(PAUSE == true)
    {
        PAUSE = false;
    }
    else
    {
        PAUSE = true;
    }
}

//shuts off the processes
void MainWindow::on_actionDont_Process_triggered()
{
    mode = NO_MODE;
}
//--------------------------------------------------------------------//


//Display frame and saving images according to chosen options---------//
void MainWindow::display_frame(cv::Mat input_image, cv::Mat color_space_image, cv::Mat segmented_image, cv::Mat damage_detected_image)
{
    if(ui->View_input->isChecked() && !input_image.empty())
    {
        QImage input_Qimage = QImage((const unsigned char*)(input_image.data),
                           input_image.cols,input_image.rows,QImage::Format_RGB888);
        ui->label->setPixmap(QPixmap::fromImage(input_Qimage));
        ui->label->resize(ui->label->pixmap()->size());
        //ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),720,120);//moving boxes in accordance to size of image
    }
    else if(ui->View_color_space->isChecked() && !color_space_image.empty())
    {
        QImage color_space_Qimage = QImage((const unsigned char*)(color_space_image.data),
                             color_space_image.cols,color_space_image.rows,QImage::Format_Indexed8);
        ui->label->setPixmap(QPixmap::fromImage(color_space_Qimage));
        ui->label->resize(ui->label->pixmap()->size());
        //ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),720,120);//moving boxes in accordance to size of image
    }
    else if(ui->View_segmented->isChecked() && !segmented_image.empty())
    {
        QImage segmented_Qimage = QImage((const unsigned char*)(segmented_image.data),
                             segmented_image.cols,segmented_image.rows,QImage::Format_Indexed8);
        ui->label->setPixmap(QPixmap::fromImage(segmented_Qimage));
        ui->label->resize(ui->label->pixmap()->size());
//        /ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),720,120);//moving boxes in accordance to size of image
    }
    else if(ui->View_damage_detection->isChecked() && !damage_detected_image.empty())
    {
        QImage damage_detected_Qimage = QImage((const unsigned char*)(damage_detected_image.data),
                             damage_detected_image.cols,damage_detected_image.rows,QImage::Format_Indexed8);
        ui->label->setPixmap(QPixmap::fromImage(damage_detected_Qimage));
        ui->label->resize(ui->label->pixmap()->size());
       // ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),720,120);//moving boxes in accordance to size of image
    }
    else if(!input_image.empty())
    {
        QImage input_Qimage = QImage((const unsigned char*)(input_image.data),
                           input_image.cols,input_image.rows,QImage::Format_RGB888);
        ui->label->setPixmap(QPixmap::fromImage(input_Qimage));
        ui->label->resize(ui->label->pixmap()->size());
      //  ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),720,120);//moving boxes in accordance to size of image
    }

    if(capture_clean_net)
    {
        capture_clean_net = false;
        Percentage_foreground_clean_net = percentage_foreground(segmented_image);
    }
    if(capture)
    {
        capture = false;
        if(!segmented_image.empty())
        {
            imwrite("Segmented_Image.png", segmented_image );
        }

        if(!damage_detected_image.empty())
        {
            imwrite("damage_detected_image.png", damage_detected_image );
        }
    }
}
//--------------------------------------------------------------------//

