# time-conversion 
## Input 
A string thats a 12-hour format time.
## Problem 
Convert to 24Hr format
## Output 
## Constraints 
## Observations 
## Solution 
Check the hour, if its in AM then if the hour is 12 then make it 00, otherwise leave it as is. If its in PM, if hour is not 12 then add 12 to it, otherwise leave 12 as is.
TC: O(1) SC: O(1) 
