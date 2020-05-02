/**
Shooting Ray
For any point (x,y), shoot a ray towards ( x + 10^9+7, y + 10^9 + 9 ), any large coprime numbers so that no integer points fall on the ray.
Next find the intersection of all edges of polygon with the ray. If intersection is odd, then inside.
But ray shooting cannot handle points on boundary. So manually check if the give point is on boundary of an edge.
if ( onboundary ) handle it
else if ( intersect is odd ) inside
else outside
**/
