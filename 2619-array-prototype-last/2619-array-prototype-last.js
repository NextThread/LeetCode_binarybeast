Array.prototype.last = function() {
    if(this[this.length - 1] == null) return -1;
    return this[this.length - 1];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */