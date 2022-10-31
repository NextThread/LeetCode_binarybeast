/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function(accounts) {
    res = 0
    for(let i = 0 ; i < accounts.length ; i++)
        {
            let perincome = 0
            for(let j = 0 ; j < accounts[i].length ; j++) perincome += accounts[i][j]
            res = Math.max(res, perincome)
        }
    return res
};