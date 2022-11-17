/**
 * @param {number} celsius
 * @return {number[]}
 */
var convertTemperature = function(celsius)
{
    let kelv=celsius+273.15;
    let far=celsius*1.80+32.00;
    const arr=[kelv,far];
    return arr;
};
