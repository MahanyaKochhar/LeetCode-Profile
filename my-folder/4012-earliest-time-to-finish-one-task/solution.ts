function earliestTime(tasks: number[][]): number
{
    let mini = 201;
    const upd = tasks.map(task => {
        return task[0] + task[1];
    });
    return Math.min(...upd);
};
