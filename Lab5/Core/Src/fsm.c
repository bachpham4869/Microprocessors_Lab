/*
 * fsm.c
 *
 *  Created on: Nov 30, 2024
 *      Author: Administrator
 */

#include "fsm.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

// Globally use
uint8_t buffer_character;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t buffer_index = 0;
uint8_t buffer_flag = 0;

// Locally use
uint8_t status = INIT;
uint8_t command_status = INIT;
uint8_t command_data[MAX_COMMAND_SIZE];
uint8_t command_data_index = 0;
// int ADC_value = 0;

bool cmdEqualRST(uint8_t str[])
{
    // Sử dụng strcmp để so sánh chuỗi
    if(strcmp((char*)str, "RST") == 0) return true;
    else return false;
}

bool cmdEqualOK(uint8_t str[])
{
	if(str[0] == 'O' && str[1] == 'K') return true;
	else return false;
}

void command_parser()
{
    switch(status)
    {
        case INIT:
            if(buffer_character == '!') status = READING;
            break;
        case READING:
            if(buffer_character != '!' && buffer_character != '#')
            {
                command_data[command_data_index] = buffer_character;
                command_data_index++;
            }

            if(buffer_character == '#')
            {
                status = PARSING;
                command_data[command_data_index] = '\0'; // Đảm bảo chuỗi kết thúc
                command_data_index = 0; // Đặt lại chỉ số
            }
            break;
        case PARSING:
            if(cmdEqualRST(command_data) == true)
            {
                command_status = RST;
            }

            if(cmdEqualOK(command_data) == true)
            {
                command_status = OK;
            }
            status = INIT; // Đặt lại trạng thái
            break;
        default:
            break;
    }
}

void uart_communication()
{
	static int last_ADC_value = 0;
	static uint8_t active_flag = 0;
	char str[100];

	switch(command_status)
	{
		case RST:
			if(active_flag == 0)
			{
				last_ADC_value = HAL_ADC_GetValue(&hadc1);
				active_flag = 1;
			}

			if (timer2_flag == 1)
			{
				HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "!ADC=%d#\r\n", last_ADC_value), 1000);
				setTimer2(300);
			}
			break;
		case OK:
			// ADC_value = -1;
			active_flag = 0;
			command_status = INIT;
			break;
		default:
			if(active_flag && timer2_flag == 1)
			{
				HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "!ADC=%d#\r\n", last_ADC_value), 1000);
				setTimer2(300);
			}
			break;
	}
}
