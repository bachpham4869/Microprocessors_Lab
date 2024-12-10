/*
 * scheduler.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Bach
 */

#include "scheduler.h"

void SCH_Delete_Task(const uint8_t TASK_INDEX){
	SCH_tasks_G[TASK_INDEX].pTask = 0;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].Runme = 0;
}

void SCH_Init(){
	uint8_t i;
	for(i = 0; i<SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i); //đảm bảo tất cả khoảng trống cho task mới bằng cách xóa hết tất cả những task trước đó
	}
}

void SCH_Add_Task(void (*pFunction) (), uint32_t DELAY, uint32_t PERIOD){
		DELAY=DELAY/TICK;
		PERIOD=PERIOD/TICK;
		uint8_t index, indexPre;
		//tìm vị trí để thêm task vào trong mảng
		for(index = 0;index < SCH_MAX_TASKS; index++){
			if(SCH_tasks_G[index].pTask == 0)
			break;
		}
		//Kiểm tra nếu là phần tử đầu tiên thì thêm task vào rồi thoát khỏi hàm
		if(index == 0){
			SCH_tasks_G[index].pTask = pFunction;
			SCH_tasks_G[index].Delay = DELAY;
			SCH_tasks_G[index].Period = PERIOD;
			SCH_tasks_G[index].Runme = 0;
			return;
		}
		//nếu mảng không còn chỗ trống thì thoát khỏi hàm
		else if(index == SCH_MAX_TASKS)
			return;
		else{
			for(int i = 0; i <= index; i++){
				//So sánh delay của task mới với các task cũ trong mảng
				if(DELAY >= SCH_tasks_G[i].Delay && SCH_tasks_G[i].pTask) {
					DELAY-=SCH_tasks_G[i].Delay;
				}
				else{
					indexPre = i;
					SCH_tasks_G[i].Delay -= DELAY;
					break;
				}
				indexPre = i;
			}
			// cập nhật lại vị trí của các tasks
			for(int i = index; i > indexPre; i--){
				SCH_tasks_G[i] = SCH_tasks_G[i-1];
			}
			//Thêm task
			SCH_tasks_G[indexPre].pTask = pFunction;
			SCH_tasks_G[indexPre].Delay = DELAY;
			SCH_tasks_G[indexPre].Period = PERIOD;
			SCH_tasks_G[indexPre].Runme = 0;
		}
}

void SCH_Update_ListTask(uint8_t index){
	for(uint8_t i = index; i < SCH_MAX_TASKS - 1; i++){
		SCH_tasks_G[i] = SCH_tasks_G[i+1]; //dịch  chuyển task lên 1 vị trí sau khi xóa tránh để lại khoảng trống
	}
		SCH_Delete_Task(SCH_MAX_TASKS-1);
}

void SCH_Dispatch_Tasks(){
	uint8_t index = 0;
	sTask temp;
	for(index = 0; index < SCH_MAX_TASKS; index ++){
		if(SCH_tasks_G[index].Runme){
			(*SCH_tasks_G[index].pTask)();
			SCH_tasks_G[index].Runme -= 1;
			temp = SCH_tasks_G[index];
			// cập nhật lại list task
			SCH_Update_ListTask(index);
			if(temp.Period){ //if task là định kỳ
				SCH_Add_Task(temp.pTask, temp.Period * TICK, temp.Period * TICK); //tác vụ được gọi lại sau thời gian định kỳ của nó
			}
		}
	}
}

void SCH_Update(){
	if(SCH_tasks_G[0].Delay == 0){
		SCH_tasks_G[0].Runme = 1;
	}
	else{
		SCH_tasks_G[0].Delay -= 1;
	}
}


