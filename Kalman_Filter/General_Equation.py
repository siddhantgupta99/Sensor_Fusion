from math import *

# sigma2 is the variance
# mu is the mean
 
def f(mu, sigma2, x):
    return 1/sqrt(2*pi*sigma2) * exp(-0.5* ( (x-mu)**2 / sigma2))

print (f(10.,4.,10.))

# In order to maximize the output of the gaussian function the value of x should be set to mu.


