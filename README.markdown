# Ruby Standard Deviation

This is a native extension to Ruby that adds a standard deviation calculation to the Array class.

## Usage

    require 'ruby-standard-deviation'
    r = [1,3,21,32,42]
    
    # calculate sample standard deviation, you can also use stdevs
    p r.stdev 
    
    # calculate population standard deviation
    p r.stdevp