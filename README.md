# EMBEDDED_ML_ASSESSMENT

This is an assignment based upon the task of image resizing using different Image Interpolation techniques and creating custom interpolation methods for resizing and comparing performance.
## Project Setup
**PREREQUISITES-**
* Ensure that you have OpenCV library installed and environment variable added.
* Make sure that you have CMake installed along with CMake tools extension for ease of selecting build kit.
* Along with CMake we need Microsoft Visual Studio Build Tools or MSVC compiler and set environment variables for CMake.
* To install MSVC refer here: [https://code.visualstudio.com/docs/cpp/config-msvc]
> NOTE: Install Microsoft Visual Studio, if you encounter the error of "could not find any instance of Visual Studio"

**RUNNING THE PROJECT**
* Clone the github repo.
* Use the following command for building the CMake: `cmake --build .\build\`
* To run main.cpp , type the following command in project directory: `.\build\Debug\embeddedAssignment.exe`
## PROJECT OUTPUT
*Original Image:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/55707f27-3274-46bb-99d7-1d2290d973d2)
*INTER_LINEAR RESULT:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/c150f218-164d-4eef-a705-3e84a1a4e5fe)
*INTER_NEAREST RESULT:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/1ce25735-d81f-4f72-a57e-e27d1ceb2e68)
*INTER_CUBIC RESULT:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/e680958d-1e5b-4d04-8df3-5df3582a6a3f)
*CUSTOM NEAREST NEIGHBOUR IMPLEMENTATION RESULT:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/2cc19084-9411-4c37-a183-555b82dc4517)
*CUSTOM BILINEAR IMPLEMENTATION RESULT:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/8ff95f86-7ff9-4ef1-a3b6-8b52f9d818d9)
*PERFORMANCE MEASUREMENT:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/bb5f0c45-ee7f-435f-946d-888268195a5b)
*PERFORMANCE COMPARISON BETWEEN CUSTOM BILINEAR AND NEAREST NEIGHBOUR:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/a6bf8c0c-b230-466b-90bc-cff377355715)

*CUSTOM BICUBIC INTERPOLATION RESULT:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/47b0eb5c-59b0-4a9f-a543-bffb79cd024c)
*PERFORMANCE FOR CUSTOM BICUBIC INTERPOLATION:*
![image](https://github.com/Kunal-Bhandari/EMBEDDED_ASSIGNMENT/assets/89692281/121b733a-030b-4672-95ad-52d55bbbff8d)



