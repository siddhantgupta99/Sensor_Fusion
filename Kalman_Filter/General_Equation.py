from math import *

# sigma2 is the variance
# mu is the mean
 
def f(mu, sigma2, x):
    return 1/sqrt(2*pi*sigma2) * exp(-0.5* ( (x-mu)**2 / sigma2))

print (f(10.,4.,10.))


# Update function takes two inputs which are prior and the measurement and outputs the posterior
def update(mean1, var1, mean2, var2):
    new_mean = (mean1*var2+mean2*var1)/(var1 + var2)
    new_var = 1/(1/var1 + 1/var2)
    return [new_mean,new_var]

print (update(10.,4.,12., 4.))

# In order to maximize the output of the gaussian function the value of x should be set to mu.


