################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/events.c" \
"../Sources/lcd.c" \
"../Sources/main.c" \
"../Sources/timer.c" \

C_SRCS += \
../Sources/events.c \
../Sources/lcd.c \
../Sources/main.c \
../Sources/timer.c \

OBJS += \
./Sources/events_c.obj \
./Sources/lcd_c.obj \
./Sources/main_c.obj \
./Sources/timer_c.obj \

OBJS_QUOTED += \
"./Sources/events_c.obj" \
"./Sources/lcd_c.obj" \
"./Sources/main_c.obj" \
"./Sources/timer_c.obj" \

C_DEPS += \
./Sources/events_c.d \
./Sources/lcd_c.d \
./Sources/main_c.d \
./Sources/timer_c.d \

C_DEPS_QUOTED += \
"./Sources/events_c.d" \
"./Sources/lcd_c.d" \
"./Sources/main_c.d" \
"./Sources/timer_c.d" \

OBJS_OS_FORMAT += \
./Sources/events_c.obj \
./Sources/lcd_c.obj \
./Sources/main_c.obj \
./Sources/timer_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/events_c.obj: ../Sources/events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/events.args" -ObjN="Sources/events_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/lcd_c.obj: ../Sources/lcd.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/lcd.args" -ObjN="Sources/lcd_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/timer_c.obj: ../Sources/timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/timer.args" -ObjN="Sources/timer_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


