from math import *

# sigma2 is the variance
# mu is the mean
 
def f(mu, sigma2, x):
    return 1/sqrt(2*pi*sigma2) * exp(-0.5* ( (x-mu)**2 / sigma2))
# In order to maximize the output of the gaussian function the value of x should be set to mu.
print (f(10.,4.,10.))


'''Update function takes two inputs which are prior and the measurement and outputs the posterior'''
def update(mean1, var1, mean2, var2):
    new_mean = (mean1*var2+mean2*var1)/(var1 + var2)
    new_var = 1/(1/var1 + 1/var2)
    return [new_mean,new_var]

print (update(10.,4.,12., 4.))

'''Predict function or motion update takes the prior input and motion's mean and variance and outputs new mean and variance'''
def predict(mean1, var1, mean2, var2):
    new_mean = mean1 + mean2
    new_var = var1 + var2
    return [new_mean, new_var]

print (predict(10., 4., 12., 4.))

''' Time to test the code '''

measurements = [5., 6., 7., 9., 10.]
motion = [1., 1., 2., 1., 1.]
measurement_sig = 4.
motion_sig = 2.
mu = 0.
sig = 10000.

for i,j in zip(measurements,motion):
# mu and sig are the inputs as well as the outputs for both equations
    [mu,sig] = update(mu,sig,i,measurement_sig)
    print ('Update : ',[mu,sig])

    [mu,sig] = predict(mu,sig,j,motion_sig)
    print ('Predict : ',[mu,sig])