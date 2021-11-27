# Assignment1





## Question 1 : *Which parameters has starter_se.py transfered to gem5? How can we change the CPU  frequency?*


The starter_se.py script gives valuable information about the Gem5 system paramters.It can be confirmed by the main() function's content.These parameters are:

1. --cpu , which refers to the CPU type. The type is set to be "Atomic".
2. --cpu-freq , which refers to the CPU frequency (clock rate) . The frequency is set to be "4GHz".
3. --num-cores, which refers to the number of cores used . They're set to be "1".
4. --mem-type , which refers to the memory type, set to be "DDR3_1600_8x8".
5. --mem-channels indicating the memory channels.They're set to be "2".
6. --mem-ranks showing the memory ranks,set to be "None".
7. --mem-size indicating the memory size,set to be "2GB".


The CPU frequency can be changed by editing the script in main.Instead of "4GHz" the user can edit the script using whatever frequncy he/she wants.

An alternative way is to create a function changeFrequency() which asks the user to type in the CLI a preferable frequency.



## Question 2: *What values do sim_seconds , sim_insts and host_inst_rate have in stats.txt?*

sim_seconds=0.000024s

sim_insts=5028 instructions per simulation

host_inst_rate=137260 inst/sec



## Question 3: *Find the CPI value : miss_penaltyl1=6 cycles,  miss_penaltyl2=50 cycles, 1 cycle cache hit/instruction*

- IL1miss_num = 332
- DL1miss_num = 179
- L2miss_num = 479
- Total_Inst_num = 5028
- 
**CPI = 6.373**



## Question 4: *What are the in-order CPU models?*


**IN-ORDER CPU MODELS**


The in-order CPU models are differensiated from the out-of-order CPUs in the form of execution.The in-order CPU  has a sequential order of executing programs.It also waits for every instruction to be executed until it continues to the next ones. Finally, it is slower in execution due to the time delays.   

### SimpleCPU

The SimpleCPU is an in-order,not detailed CPU.It contains warm up periods (warm up period:The time that the simulation runs before it gathers the results).It also contains client systems that use a specific server.Furthermore, SimpleCPU can evaluate if a program runs correctly.It consists of :
BaseSimpleCPU , AtomicSimpleCPU , TimingSimpleCPU


#### BaseSimpleCPU
 
Atomic and Timing SimpleCPU inherit BaseSimpleCPU which justifies the fact that it cannot run on its own.It is responsible for creating functions that are related to program interruptions,controlling the instruction fetch,implementing the execution context. (Instructions-Parameters-Result)


#### AtomicSimpleCPU

While connecting to cache, it functions "atomically", which means that it uses only one step to implement an instruction.It computes the overall time connection to cache by adding all the delays from the atomic accesses and contains functions for write and read.Additionally it keeps time,it is responsible for frequency of CPU,it defines the port to connect with memory and controls the connection between CPU and cache.  


### TimingSimpleCPU
It connects to the memory through time.TimingSimpleCPU waits for the system to respond before it starts the procedure.It is inherited by Base and has the same functions. It also defines the port that is used to hook up to memory.


## -Minor CPU Model
It is an in-order model with stable pipeline, configurable structures and behavior.It is used in strictly in-order models through the order MinorTrace/minorview.py format/tool.Minor CPU is implemented in a similar way to other gem5 models through Python. It can indirectly multithread using thread comments.

*Pipelining is a technique where multiple instructions are overlapped during execution.*
