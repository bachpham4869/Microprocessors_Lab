/*
 * scheduler.h
 *
 *  Created on: Nov 25, 2024
 *      Author: Bach
 */

#include "stdint.h"

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define SCH_MAX_TASKS	40 //số lượng tasks tối đa
#define NO_TASK_ID	0
#define TICK 10

typedef struct{
	void (*pTask) (void);
	uint32_t Delay; //toggle
	uint32_t Period; //chu kỳ của task
	uint32_t Runme;
	uint32_t TaskID;
} sTask;



sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void);
void SCH_Delete_Task(const uint8_t TASK_INDEX);
void SCH_Add_Task(void (*pFunction) (), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update_ListTask(uint8_t index);
void SCH_Update();
void SCH_Dispatch_Tasks();

#endif /* INC_SCHEDULER_H_ */
