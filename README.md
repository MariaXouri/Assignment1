# Assignment1




**FILE NAMES**

hello_result : stats for question 2

m5-minor : gem5 MinorCPU results

m5-timingsimp : gem5 TimingSimpleCPU results

m5MinorFreq : gem5 MinorCPU results with 0.5GHz frequency 

m5MinorMemor : gem5 MinorCPU results with HBM_1000_4H_1x64 ruby

m5TimingSimpleMemor : TimingSimpleCPU with HBM_1000_4H_1x64 ruby

m5TimingSimpFreq : TimingSimpleCPU results with 0.5GHz frequency 





## Question 1 : *Which characteristics has starter_se.py transfered to gem5? How can we change the CPU  frequency?*


The starter_se.py script gives valuable information about the Gem5 system characteristics.It can be confirmed by the main() function's content.These characteristics are:

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

 **CPI = 6.373**



## Question 4: *What are the in-order CPU models?*


**IN-ORDER CPU MODELS**


The in-order CPU models are differensiated from the out-of-order CPUs in the form of execution.The in-order CPU  has a sequential order of executing programs.It also waits for every instruction to be executed until it continues to the next ones. Finally, it is slower in execution due to the time delays.They are also statically scheduled.  


### 1. SimpleCPU

The SimpleCPU is an in-order,not detailed CPU.It doesn't use pipelines and functions fast. It contains warm up periods (warm up period:The time that the simulation runs before it gathers the results).It also contains client systems that use a specific server.Furthermore, SimpleCPU can evaluate if a program runs correctly.It consists of :
BaseSimpleCPU , AtomicSimpleCPU , TimingSimpleCPU


#### BaseSimpleCPU
 
Atomic and Timing SimpleCPU are inherited by BaseSimpleCPU which justifies the fact that it cannot run on its own.It is responsible for creating functions that are related to program interruptions,controlling the instruction fetch,implementing the execution context. (Instructions-Parameters-Result)


#### AtomicSimpleCPU

While connecting to cache, it functions "atomically", which means that it uses only one step to implement an instruction.It computes the overall time connection to cache by adding all the delays from the atomic accesses and contains functions for write and read.The atomic access is faster than a detailed access. Memory requests finish immediately without any resource contention or queuing delay.
Additionally it keeps time,it is responsible for frequency of CPU,it defines the port to connect with memory and controls the connection between CPU and cache.  


#### TimingSimpleCPU
It connects to the memory through time.TimingSimpleCPU waits for the system to respond before it starts the procedure.It is inherited by Base and has the same functions. It also defines the port that is used to hook up to memory.Timing access is more detailed, includes resource contention or queuing delay.
Memory requests actually take time to go through to the memory system.



### 2. Minor CPU Model
It is an in-order model with stable pipeline, configurable structures and behavior.It is used in strictly in-order models through the order MinorTrace/minorview.py format/tool.Minor CPU is implemented in a similar way to other gem5 models through Python. It can indirectly multithread using thread comments.Structures have fixed sizes and the data are in queues and FIFOs.
It can provide data and instruction interfaces for connection to a cache system.

*Pipelining is a technique where multiple instructions are overlapped during execution.*

1. Fetch1

Fetch1 is responsible for fetching cache lines or partial cache lines from the I-cache and passing them on to Fetch2.

2. Fetch2

Fetch2 receives a line from Fetch1 into its input buffer, breaks it to instructions. It contains the branch prediction mechanism.

3. Decode 

Decode takes a vector of instructions from Fetch2 and packs them into its output instruction vector.


4. Execute 

Execute provides the instruction execution and memory access. An instructions passage can take multiple cycles with its timing modelled by a functional unit pipeline FIFO.

## Question 4a: *Using stats.txt determine the simulation time of MinorCPU and TimingSimpleCPU*

   **Minor Cpu:**
   sim_seconds 0.000043

   **TimingSimpleCpu:**
   sim_seconds 0.000051


## Question 4b: *Which CPU between TimingCPU and MinorCPU has bigger sensitivity in frequency and memory changes and why?*

- Frequency changes:If we change the frequency to 0.5GHz we have those statistics:



**INSTRUCTION RATE - SIMULATION TIME**

MinorCPU - default : 214636   

MinorCPU 0.5 GHz :   174543

**Result :** 18.7% change in instruction rate | 93% change in simulation time 

-------------------------------------------------------------------------



TimingSimpleCPU - default : 515305

TimingSimpleCPU 0.5 GHz : 317025

**Result :** 38.4% change in instruction rate | 115% change in simulation time 

----------------------------------------------------------------------------


*TimingSImpleCPU has a bigger change in instruction rate and simulation time.*



- Memory changes : If we change the memory to HBM_1000_4H_1x64  we have those statistics : 



**INSTRUCTION RATE - SIMULATION TIME**

MinorCPU - default : 214636

MinorCPU  HBM_1000_4H_1x64 :  110158

**Result :** 48.7% change in instruction rate | 4.6% change in simulation time 

---------------------------------------------------------------------------



TimingSimpleCPU - default : 515305

TimingSimpleCPU 0.5 GHz : 195290

**Result :** 74% change in instruction rate | 3.9% change in simulation time 



*TimingSImpleCPU has a bigger change in instruction rate and a smaller change in simulation time.*



**Explaination** : TimingSimpleCPU has no pipeline system.This means that it stalls on every memory request waiting for a response. If we change some parameters, the instruction rate will fall in a larger amount due to the time delays.This makes TimingSimpleCPU more sensitive to memory and frequency alterations.With different memory technology, it seems that simulation seconds are more affected in the minor cpu. As the memory access changes, the instruction processes in the pipeline with different speed.












