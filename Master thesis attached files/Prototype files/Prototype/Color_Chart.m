function RGB = Color_Chart(N)

%

violet = [148 0 211];
yellow = [255 255 0];
red = [255 0 0];
green = [0 255 0];
blue = [0 0 255];
cyan = [0 255 255];
dark_green = [0 100 0];
indian_red = [205 92 92];


colors = [dark_green;yellow;red;green;blue;violet;cyan;indian_red];

% while N>8
%    N = N-8;
% end
if N == 2
    RGB = colors(3,:);
end
if N==1
    RGB = [255, 255, 255];
end
if N==3;
    RGB = [0,100,0];
end
if N==0
    RGB = [0,0,0];
end

end