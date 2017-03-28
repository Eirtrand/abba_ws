clc
clear all
close all
%% This program takes in an image of a damaged net, extracts the xyY color
%% scheme, divides up the image into many subimages and using segmentation 
%% and region growing finds the biggest "hole" in the net

%% image as input
start_net = imread('damaged_net.jpg');
net = start_net(1:300,:,:);% for damaged_net.jpeg
% net = start_net;

%% video as input
% %read video and take out image
% readerobj = VideoReader('video1_good_with_rope.mp4');
% % Read in all video frames.
% vidFrames = read(readerobj);
% numFrames = get(readerobj, 'NumberOfFrames');
% % Create a MATLAB movie struct from the video frames.
% for k = 1 : numFrames
%     mov(k).cdata = vidFrames(:,:,:,k);
%     mov(k).colormap = [];
% end
% 
% [net_uncut,map] = frame2im(mov(1));
% 
% net = Cut_Image(net_uncut);
% 
% figure();
% imshow(net);
% title('input image')

%% Segmentation based on the xyY space

% Utilization of the xyY space, involving the processing
% of the two channels (i.e., luminance and chrominance) as well as
% their interaction, allows for significantly reduced computational cost
% compared to an approach using the RGB space. Tests have shown that the
% luminance wokrs very good with underwater images.

%Transforming image to the XYZ color space

XYZ_net = zeros(size(net));
xyY_net = zeros(size(net));

for i = 1:size(XYZ_net,1)
    for j = 1:size(XYZ_net,2)
        XYZ_net(i,j,1) = 0.607*net(i,j,1)+0.174*net(i,j,2)+0.200*net(i,j,3); 
        XYZ_net(i,j,2) = 0.299*net(i,j,1)+0.587*net(i,j,2)+0.114*net(i,j,3);
        XYZ_net(i,j,3) = 0.066*net(i,j,2)+1.111*net(i,j,3);
        
        xyY_net(i,j,1) = 255*XYZ_net(i,j,1)/(XYZ_net(i,j,1)+XYZ_net(i,j,2)+XYZ_net(i,j,3));
        xyY_net(i,j,2) = 255*XYZ_net(i,j,2)/(XYZ_net(i,j,1)+XYZ_net(i,j,2)+XYZ_net(i,j,3));
        xyY_net(i,j,3) = XYZ_net(i,j,2);
        
    end
end

% x and y doesnt seem useful for our purposes
x_net = xyY_net(:,:,1);


y_net = xyY_net(:,:,2);


luminance_net = xyY_net(:,:,3);
figure();
imshow(uint8(luminance_net))
title('luminance, xyY')


%% Segmentation using edge detection from Digital image processing using matlab(Gonzales, Woods,Eddins)
fp = zeros(size(luminance_net));
total_grad = zeros(size(luminance_net));

c=0;
d=0;
e=0;
f=0;

for a = 0:9
    if a == 0
        c=1;
        d = floor(size(luminance_net,1)*0.1);
    else
        c=d+1;
        d = d+floor(size(luminance_net,1)*0.1);
    end
    for b = 0:9
        

        if b == 0
            e = 1;
            f = floor(size(luminance_net,2)*0.1);
        else
            e = f+1;
            f = f+floor(size(luminance_net,2)*0.1);
        end
        
        lumi = uint8(luminance_net(c:d,e:f,:));


        filter = fspecial('gaussian',[3 3], 0.5);
        filtered_luminance_net = imfilter(lumi, filter, 'replicate');

        lumi = double(filtered_luminance_net);


        sx = fspecial('sobel');
        sy = sx';
        % using luminance image
        % gx = imfilter(lumi,sx,'replicate');
        % gy = imfilter(lumi,sy,'replicate');
        %using chromatic x image
        gx = imfilter(lumi,sx,'replicate');
        gy = imfilter(lumi,sy,'replicate');

        grad = sqrt(gx.*gx+gy.*gy);
        grad = grad/(max(grad(:)));


        h = imhist(grad);
        changeable_variable = 0.65; %works well for image with hole
%       changeable_variable = 0.45; %works well with video
        Q = percentile2i(h,changeable_variable);

        marker_image = grad > Q;
        fpx = lumi.*marker_image;
        fp(c:d,e:f)=fpx;
        total_grad(c:d,e:f) = grad;
    end
end



figure();
imshow(fp);
title('result from merging together sub-images')
figure();
imshow(total_grad);
title('result before percentile')

        %performing morphological thinning

        %with dilation
        bw1 = bwmorph(fp,'dilate',1);
        figure();
        imshow(bw1);

        bw2 = bwmorph(bw1,'thin',Inf);
        figure();
        imshow(bw2);
        title('thinned net, dilated, from luminance');

        bw3 = bwmorph(bw2,'spur',Inf);%removes end points of lines
        figure();
        imshow(bw3);
        title('Thinned net, dilated, spurred,from luminance')

        %without dilation
        bw2 = bwmorph(fp,'thin',Inf);
        figure();
        imshow(bw2);
        title('thinned net, from luminance');

        bw3 = bwmorph(bw2,'spur',Inf);%removes end points of lines
        figure();
        imshow(bw3);
        title('Thinned net, spurred,from luminance')
        %% Region Growing

        %adding a border of 5 white pixels along the image, due to part of the net
        %along th border disapears during morphological operations

        for i = 1:size(bw2,1)
            for j = 1:5
                bw2(i,j)=1;
                bw2(i,size(bw2,2)+1-j)=1;
            end
        end

        for i = 1:5
            for j = 1:size(bw2,2)
                bw2(i,j)=1;
                bw2(size(bw2,1)+1-i,j)=1;
            end
        end
        figure();
        imshow(bw2)
        bw = uint8(bw2);
        t = 0;
        deleted = 0;
        diff = [];
        stepin = 0;
        suspect_regions = [];%regions found to be abnormally large

        for x = 1:size(bw,1)
           for y = 1:size(bw,2)
                  if bw(x,y)==0
                      t = 0;
                      region = [];
                      s_region = [x;y];
                      change = 1;
                      bw(x,y) = 3;
                      while change > 0 
                          t = t+1;
                          change = 0;
                          s = size(s_region);
                          for n = s(2):-1:1
                              for i = -1:1
                                  for j = -1:1
                                      if abs(i)~=abs(j)%4-connectivity

                                          if (s_region(1,n)+i>0) && (s_region(2,n)+j)>0 && (s_region(1,n)+i)<(size(bw,1)) && (s_region(2,n)+j)<(size(bw,2))%keeping inside boundary
                                              if bw(s_region(1,n)+i,s_region(2,n)+j)==0
                                                  bw(s_region(1,n)+i,s_region(2,n)+j) = 3;
                                                  change = 1;
                                                  s_region = [s_region,[s_region(1,n)+i;s_region(2,n)+j]];
                                              end
                                          end
                                      end
                                  end
                              end
                              region = [region,s_region(:,n)];
                              s_region(:,n)=[];

                          end

                      end

                      region = [region, s_region];
                      if size(region,2)>2000 %saves the numberof pixels and the "box" pixels for each suspect region
                          for n = 1:size(region,2)
                              bw(region(1,n),region(2,n)) = 2;%indicating a too big hole
                          end
                          suspect_regions = [suspect_regions,[size(region,2);min(region(1,:));max(region(1,:));min(region(2,:));max(region(2,:))]];
                      end
                  end
           end
        end

        %making a color mask which shows the different regions in different colors
        color_mask = zeros(size(net));
        % zeros(image_size(2),image_size(1),image_size(3));
        for x = 1:size(color_mask,1)
           for y = 1:size(color_mask,2)
               color=bw(x,y);
               color_mask(x,y,:)=Color_Chart(color);

           end
        end
        figure();
        imshow(color_mask);
        title('Red indicates possible broken net areas')



%% Retesting the suspect regions, and show regions that are not on the border
found = 0;
if size(suspect_regions,2)>0        
        while found == 0
            [i,j] = find(suspect_regions==max(suspect_regions(1,:)));
            if suspect_regions(2,j) ~= 1 && suspect_regions(3,j) ~= size(color_mask,1) && suspect_regions(4,j) ~= 1 && suspect_regions(5,j) ~= size(color_mask,2)%kan byttte til eller
                suspect = color_mask(suspect_regions(2,j):suspect_regions(3,j),suspect_regions(4,j):suspect_regions(5,j),:);
                figure();
                subplot(1,2,1)
                imshow(suspect);
                title('suspect area');
                subplot(1,2,2)
                imshow(net(suspect_regions(2,j):suspect_regions(3,j),suspect_regions(4,j):suspect_regions(5,j),:))
                found = 1;

            else
                figure();
                imshow(color_mask(suspect_regions(2,j):suspect_regions(3,j),suspect_regions(4,j):suspect_regions(5,j),:))
                suspect_regions(:,i)=[];
            end
        end
end






