function I = percentile2i(h,P)

%taken from Digital image processing using matlab (Gonzales, Woods, Eddins)

if P<0 || P>1
    error('The percentile must be in range [0, 1].')
end

%normalizing the histogram to unit area
h = h/sum(h);

%cumulative distribution
C = cumsum(h);

% Calculations
idx = find(C>=P,1,'first');
%Subtract 1 from idx because indexing starts at 1, but intensities start at
%0. also normalize to the range [0, 1].
I= (idx-1)/(numel(h)-1);
end