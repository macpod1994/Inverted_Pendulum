function dw = rhs(t,w,tster,sterowanie,c)
u = interp1(tster,sterowanie,t);
dw = -c(1)*w + c(2)*u;