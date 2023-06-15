/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function (fn) {
  return this.reduce((map, c) => {
    const id = fn(c);
    map[id] ? map[id].push(c) : (map[id] = [c]);
    return map;
  }, {});
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */