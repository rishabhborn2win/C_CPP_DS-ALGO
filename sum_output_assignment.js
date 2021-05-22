
var a1 = [-22,7,-89].reverse();
var a2 = [-22,7,-89].reverse();
var output=[], carry=0;
// var arrString1 = prompt("Enter the array 1 (For e.g [1,2,3,4] So enter 1,2,3,4): ");
// var arrString2 = prompt("Enter the array 2 (For e.g [1,2,3,4] So enter 1,2,3,4): ");
// var a1 = arrString1.split(',').reverse();
// var a2 = arrString2.split(',').reverse();


  if(a1.length > a2.length){
    //swapping the array
    temp = a1;
    a1=a2;
    a2=temp;
}

//starting with the smallest array first element
for(var i =0; i<a1.length ; i++){
    //adding the same index length number
    var sum = Number(a1[i])+Number(a2[i])+carry;
    var unit = sum%10;
    output.unshift(unit);
    if(sum>0){
        carry = Math.floor(sum/10);
        }else{
            carry = Math.ceil(sum/10);
        }
}
//left element of the array whose size is bigged
for(var j=a1.length; j<a2.length; j++){
    var sum = Number(a2[j]) + carry;
    var unit = sum%10;
    output.unshift(unit);
    if(sum>0){
    carry = Math.floor(sum/10);
    }else{
        carry = Math.ceil(sum/10);
    }
}
//checking if the carry is left so displaying it as unit digit
while(carry > 0){
    output.unshift(carry%10);
    carry = Math.floor(carry/10);
}
while(carry < 0){
    output.unshift(carry%10);
    carry = Math.ceil(carry/10);
}

//output array is the final array
console.log(output);