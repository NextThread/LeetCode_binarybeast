function minimumBoxes(apple: number[], capacity: number[]): number {
       let sumApples = apple.reduce((a, b) => a + b, 0)
    capacity.sort((a, b) => b - a)
    let sumCapacity = 0
    for (let i = 0; i < capacity.length; i++) {
        sumCapacity += capacity[i]
        if (sumCapacity >= sumApples) {
            return i + 1
        }
    }
    return capacity.length
};