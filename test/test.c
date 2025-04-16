// #include "Task.h"
// #define MAX_TASKS 100
// void OsIdle(void) 
// {
//     while(1)
//     {
//         // 输出任务的优先级
//         printf("Idle is running!\n");
//     }
// }

// int main()
// {
//     // 定义资源和事件
//     // Resource resources[] = {{1, false}, {2, false}};
//     // Event events[] = {{1, false}, {2, false}};
    
//     // 定义时间保护
//     // TimingProtection timingProt = {100, 50, 20};


//     // 定义并初始化任务属性
//     TaskProperty Tasks[MAX_TASKS] = 
//     {
//         {
//             .TaskId = 0,
//             .TaskName = "Idle Task",
//             .Entry = OsIdle,
//             .TaskType = BasicTask,
//             .Priority = 255,
//             .StackSize = 1024,
//             .ActivationCount = 10,
//             .Autostart = true,
//             .ScheduleType = FullPreemptive,
//             .TaskState = SUSPENDED,
//         }
//     };
//     // InitTaskProperty(&task1, BasicTask, 1, 1024, 1, true, FullPreemptive,
//     //                  resources, 2, events, 2, timingProt);
    
//     // 创建任务
//     CreateTask(&Tasks);

//     // 启动操作系统
//     StartOS();

//     // main 函数不应该返回
//     return 0;
    
// }

#include "task.h"

DeclareTask(Task1);
DeclareTask(Task2);

void Task1(void) {
    printf("Task1 is running.\n");
}

void Task2(void) {
    printf("Task2 is running.\n");
}

int main(void) {
    ActivateTask(0);  /**< Activate Task1 */
    ActivateTask(1);  /**< Activate Task2 */

    Schedule();  /**< Schedule a task */
    Task1();

    Schedule();  /**< Schedule the next task */
    Task2();

    return 0;
}
