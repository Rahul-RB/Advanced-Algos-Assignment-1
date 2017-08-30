Personal Details: 
	USN: 01FB15ECS366
	NAME: Rahul R Bharadwaj

---Notes start---
The report.pdf is a very compressed due to limit imposed on the number of pages(to a 'couple'). But I please suggest that you go to PLOTS/ directory to see the output plots for all increment and decrement factors. Please do read the 'Last Notes' at end. Thank you!
---Notes end-----


Project Structure: 

1. The 'C' files, where everything has been implemented as: 
	a. headers.h  		--> file with all the headers, strcuture definitions and function declarations.
	b. dynamicTable.c 	--> file with all function implementations.
	c. run.c 			--> client file, used to run inputs and get outputs.
	d. opsArray.h 		--> has a #define ARRAY {1,0...} , which is the array of operations, where a '0' is pop and '1' is push.

2. 'Python' files for plotting and analyzing the outputs:
	a. analysis.py 		--> a file which uses the 'subprocess' module to generate output from the C programs above
						--> and get the output, which is the time of each individual operation -pop and push into two arrays.
						--> and plot the graphs of number of operations vs time for operations using matplotlib.

	b. generateRandomSequence.py
						--> a file to generate the random sequence of 0's and 1's needed for opsArray.h 

Other Files: 
	Matrix-Outputs.ods 	--> excel sheet having all outputs tabulated in a table.


Running the project 

--------------------------------BEFORE RUNNING ANY COMMANDS, PLEASE DO THE FOLLOWING CHECK: --------------------------------
1. TO test the Data Structure against 3:2 ratio of inputs(pushes) to deletions(pops), go to opsArray.h and uncomment the second #define
	if not already done. Similarly, for 4:2 uncomment the #define corresponding to that i.e. the first #define. 

2. Then go to run.c and do the following:
	a. If you're testing for 3:2 , then uncomment the for loops regarding that (it's the first set of 'for' loops). 
	b. If you're testing for 4:2 , then uncomment the for loops regarding that (it's the second set of 'for' loops). 
	c. An extra set of 'for' loops are present at end, which tests for 1:1 ratio, in consecutive order, use it for any testing.

--------------------------------ONLY AFTER DOING ABOVE CHECKS, PROCEED TO STEPS BELOW  --------------------------------------
a. To test the data structure.
	1. Run $make command in terminal.
	2. $./a.out <PARAM1> <PARAM2> > outputs.txt
		where, <PARAM1> is either "incr" or "decr" (without quotes) indicating "incr" for "incrementing factor"
		and "decr" for "decrementing factor".
		and, <PARAM2> is the factor itself. Give a floating point number as argument.
		EXAMPLE: 
		$./a.out incr 2 > outputs.txt    		--> indicating that the data structure will now run for incrementing factor '2'
		$./a.out decr 0.75 > outputs.txt    	--> indicating that the data structure will now run for incrementing factor '0.75'

		NOTE: OUTPUTS ARE STORE IN outputs.txt in same directory, if you run the code as shown above.

b. To get the graphs and see them:
	1. Make sure your computer has matploblib installed on python3 (sudo -H pip3 install matplotlib)
	2. Run $python3 analysis.py
	3. See the graphs correspondingly.

c. TO RUN THE CODE, GET THE OUTPUTS AND PLOT THE GRAPHS AT SAME TIME:
	A provision of a exec.sh shell script file has been made for this purpose.
	1. Run $chmod +x exec.sh to make it an executable file.
	2. Run #./exec.sh <PARAM1> <PARAM2>
		where <PARAM1> and <PARAM2> are the SAME as defined in a.2. above.


Last Notes: 

	This assignment has been a lot of fun doing over the past 4-5 days. It helped me realise more stuff in C than ever before, showed me the various silly mistakes I commit. I used gdb extensively for debugging even simple bugs to get used to gdb. 
	