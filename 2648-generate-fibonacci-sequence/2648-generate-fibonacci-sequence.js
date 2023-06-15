/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
      let i = 0, fibs = [0, 1];
    while (true) {
        if (i == fibs.length) fibs.push(fibs[i - 1] + fibs[i - 2]);
        yield fibs[i++];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */