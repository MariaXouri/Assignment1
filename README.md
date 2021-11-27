# Assignment1





## Question 1 : *Which parameters has starter_se.py transfered to gem5? How can we change the CPU  frequency?*


The starter_se.py script gives valuable information about the Gem5 system paramters.It can be confirmed by the main() function's content.These parameters are:

1.--cpu , which refers to the CPU type. The type is set to be "Atomic".
2.--cpu-freq , which refers to the CPU frequency (clock rate) . The frequency is set to be "4GHz".
3.--num-cores, which refers to the number of cores used . They're set to be "1".
4.--mem-type , which refers to the memory type, set to be "DDR3_1600_8x8".
5.--mem-channels indicating the memory channels.They're set to be "2".
6.--mem-ranks showing the memory ranks,set to be "None".
7.--mem-size indicating the memory size,set to be "2GB".


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







**IN-ORDER CPU MODELS**

The in-order CPU models are:

## -SimpleCPU

SimpleCPU consists of : BaseSimpleCPU , AtomicSimpleCPU , TimingSimpleCPU

### BaseSimpleCPU


### AtomicSimpleCPU



### TimingSimpleCPU







## -Minor CPU Model
