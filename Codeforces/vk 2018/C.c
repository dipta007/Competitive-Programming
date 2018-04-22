var n = readline();
var numbers = readline().split(" ").map(function(x) { return parseInt(x); });

var white = 0, blk = 0;
var fw = 0, fb = 0;
var fixW, fixB;
var flg = 1;
for(var i=0; i<n; i++)
{
    if(numbers[i] == 0)
    {
    	if(blk)
        {
            if(fb == 0) fixB = blk;
            else if(blk != fixB) flg = 0;
            fb = 1;
            blk = 0;
        }

        white+=1;
    }
    else
    {
        if(white)
        {
            if(fw == 0) fixW = white;
            else if(white != fixW) flg = 0;
            fw = 1;
            white = 0;
        }

        blk += 1;
    }
}

if(white)
{
    if(fw == 0) fixW = white;
    else if(white != fixW) flg = 0;
    fw = 1;
    white = 0;
}

if(blk)
{
    if(fb == 0) fixB = blk;
    else if(blk != fixB) flg = 0;
    fb = 1;
    blk = 0;
}

if(flg) print("YES\n");
else print("NO\n");
