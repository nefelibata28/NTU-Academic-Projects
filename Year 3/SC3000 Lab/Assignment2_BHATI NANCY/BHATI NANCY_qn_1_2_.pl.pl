%prolog clauses

%sumsum, a competitor of appy
competitor(sumsum, appy). 

%sumsum developed galactica-s3
developed(sumsum, galacticas3).

%stevey stole galactica-s3
stole(stevey, galacticas3). 

%stevey is the boss of appy
boss(stevey,appy). 

%unethical for a boss to steal business from rival companies
unethical(Boss) :- boss(Boss, Company), stole(Boss, Technology), business(Technology), rival(Competitor, Company). 

% competitor is a rival. here, competitor and company are variables not constants
rival(Competitor, Company) :- competitor(Competitor, Company). 

% some nice smart phone technology called galactica-s3
smart_phone_technology(galacticas3). 

%smart phone technology as business
business(Technology) :- smart_phone_technology(Technology).