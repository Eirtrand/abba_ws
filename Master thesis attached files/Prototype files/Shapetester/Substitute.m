function cost_of_action = Substitute(Canonical_Test_Shape,Canonical_Dictionary_Shape,i,j,cost_of_sub)

%Substiture runs the substitute routine

%cost_of_action = Substitute(Canonical_Test_Shape,Canonical_Dictionary_Shape,i,j,cost_of_sub)
%takes 2 shapes a place in the shape numbers for both shapes and the cost
%of substituting and gives back the cost of substituting a number in the
%test shape to a number in the dictionary shape, if the numbers in space i
%and j are the same the cost is 0, if we are out of bounds the cost is huge
%since that is an illegal action

if j < length(Canonical_Test_Shape)+1 && i < length(Canonical_Dictionary_Shape)+1
    if Canonical_Test_Shape(j-1)== Canonical_Dictionary_Shape(i-1)
        cost_of_action = 0;%To keep a number is a free action
    else
        cost_of_action = cost_of_sub;%substitute a number has a given cost
    end
else
    cost_of_action = 100;%big number so action will not be chosen as it would get us out of bounds
end

end