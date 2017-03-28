function [histogram,x] = Histogram_Maker(image)

histogram = zeros(255,1);
x = 1:255;
for k = 1:255
    num_el = size(find(image==k));
    histogram(k) = num_el(1);
end

end


