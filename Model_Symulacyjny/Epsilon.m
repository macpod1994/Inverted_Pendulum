close all;
%% pomiary
load('pomiar.mat');
load('params');
t = Data.time;
u = Data.signals(1).values;
fi = Data.signals(2).values;
fi_pr = Data.signals(3).values;
th = Data.signals(4).values;
w = Data.signals(5).values;

%% parametry do symulacji
Jr = J_sm + m_wah*L^2;
M = 0.530;
D = m_wah^2*L^2/Jr;
g = 9.81;

%% normalizacja
fi_norm = fi;
fi_norm(fi<0) = fi_norm(fi<0)+2*pi;
fi_pr_norm = [diff(fi_norm)./(t(2)-t(1));0.028];
u_mod = u;
u_mod(t<2) = zeros(size(u_mod(t<2)));
% figure(6);
% plot(t,u_mod,t,u);

%% identyfikacja dynamiki wózka s' = -c1*s + c2*u
w0 = 0;
c1 = 5.8;
c2 = -18;
c = [c1;c2];
blad(t,w0,t,u_mod,w,c)
%% linearyzacja
A = [0 1 0 0
    m_wah*g*L/Jr 0 0 m_wah*L*c1/Jr
    0 0 0 1
    0 0 0 -c1];
B = [0; -m_wah*L*c2/Jr; 0; c2];
C = eye(4);
D = zeros(4,1);
x0 = zeros(4,1);
%% Simulink
% sim('wahadlo_model3.slx');
tSim = fi_pr_Sim.time;
fiPrSim = fi_pr_Sim.signals(1).values;
fi_Sim = fiSim.signals(1).values;

%% porównanie modelu z pomiarami
% plot(t,u,t,w);
figure(2);
plot(t(t<15),fi_norm(t<15),'r',tSim,fi_Sim,'b');
figure(3);
plot(t(t<15),fi_pr_norm(t<15),'r',tSim,fiPrSim,'b');

%% identyfikacja t³umienia wahad³a
load('Okres1.mat');
% figure(9);
cz = Okres.time;
fi = Okres.signals(2).values;
fi_norm = fi;
fi_norm(fi<0) = fi_norm(fi<0)+2*pi;
% plot(cz,fi_norm);
%% LQR
Q = [10 0 0 0
    0 10 0 0
    0 0 0.1 0
    0 0 0 1];
R = 1e2;
[K,S,e] = lqr(A,B,Q,R)