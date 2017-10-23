function e = blad(t,w0,tu,u,wzorzec,c)
    [T Y] = ode45(@(t,w0)rhs(t,w0,tu,u,c),t,w0);
    e = sum((wzorzec-Y).^2);
    figure(5);
    plot(t,Y,t,wzorzec);