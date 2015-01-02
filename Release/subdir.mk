################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RgbImage.cpp \
../dingen.cpp \
../lijst.cpp \
../main.cpp \
../objecten.cpp 

OBJS += \
./RgbImage.o \
./dingen.o \
./lijst.o \
./main.o \
./objecten.o 

CPP_DEPS += \
./RgbImage.d \
./dingen.d \
./lijst.d \
./main.d \
./objecten.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<" -fpermissive
	@echo 'Finished building: $<'
	@echo ' '


