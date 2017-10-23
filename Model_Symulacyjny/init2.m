%% pomiary
m_ciezarka=0.011;
m_rurki=0.02;
d_wahadla = 0.41;
d_wystajacego = 0.085;
srodek_ciez = 0.337; %od góry 

%% obliczenie analityczne J
J_anal = 2*(m_rurki/3*((0.41/0.495)*0.41^2 + (0.085/0.495)*0.085^2) + m_ciezarka*d_wahadla^2); % mom. bezw. wzgledem osi obrotu

%% obliczenie ekspery. J
load('Okres1.mat');
t = Okres.time(1000:end);
pos = Okres.signals(2).values(1000:end);
wah = diff(sign(pos));
z = t(wah>0);
okr = mean(diff(z));
J_eksp = (okr/(2*pi))^2*2*(m_ciezarka+m_rurki)*9.81*(srodek_ciez-d_wystajacego);
blad = abs(J_anal - J_eksp);

%% obliczenie J wzgl SM
J_zaw = (J_anal + J_eksp)/2;
J_sm = J_zaw - 2*(m_ciezarka+m_rurki)*(srodek_ciez-d_wystajacego)^2; % wzg. sr. masy. z tw. Steinera
J_sm_a = 2*(m_ciezarka+m_rurki)/3*((0.337/0.495)*0.337^2+(0.495-0.337)/0.495*(0.495-0.337)^2);
blad_sr = abs(J_sm-J_sm_a);

L = srodek_ciez-d_wystajacego;
m_wah = 2*(m_ciezarka + m_rurki);



