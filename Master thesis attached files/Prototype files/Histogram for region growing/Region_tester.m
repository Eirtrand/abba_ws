clc
clear all
close all


% reading in filw with region sizes
text_Regions = fileread('new_ref_vid_tweak_region_sizes.txt');
Regions = str2num(text_Regions);

[histogram,x] = Region_Histogram_Maker(Regions);
figure();
x = [-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,x];
histogram = [0;0;0;0;0;0;0;0;0;0;histogram];
plot(x,histogram);



