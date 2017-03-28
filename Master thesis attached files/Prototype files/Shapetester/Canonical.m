function Canonical_Shape = Canonical(Shape)

%Canonical changes a shape number to its canonical form

%Canonical_Shape=Canonical(Shape) takes in a shape number, transform it
%to its canonical form and outputs that canonical form

shape_size=size(Shape);
shape_length = shape_size(2);
unique = 0;
n=0;%starting segment length
candidate_number = 1:shape_length;
potential_candidate_number =[];

%finding the starting point for the canonical shape
while unique == 0
    n = n+1;
    candidates = 0;
    smallest_num_val = 10^10;%high number just to get lower than that
    s=size(candidate_number);
    candidate_number_length = s(2);
   
    for i = 1:candidate_number_length%endret til å bare sjekke punktene i candidate_number
        numerical_value = 0;
        for j = 0:n-1
            if candidate_number(i)+j>shape_length %wraparound procedure when we get out of bounds
                numerical_value = numerical_value+Shape(candidate_number(i)+j-shape_length);
            else
                numerical_value = numerical_value+Shape(candidate_number(i)+j);
            end
        end
        
        if numerical_value == smallest_num_val
            potential_candidate_number = [potential_candidate_number , candidate_number(i)];
            candidates = candidates+1;
        elseif numerical_value < smallest_num_val
            potential_candidate_number = [candidate_number(i)];
            candidates = 1;
            smallest_num_val = numerical_value;
        end
    end
    if candidates == 1
        unique = 1;
    elseif candidates == 0
        unique = 1;
    end
    candidate_number = potential_candidate_number;
    
end

%making the canonical shape using the shape number found above
if candidate_number >1
    Canonical_Shape = [Shape(candidate_number:shape_length),Shape(1:candidate_number-1)];
elseif candidate_number == 1
    Canonical_Shape = Shape;
    'Given shape was aready in Canonical form'
end