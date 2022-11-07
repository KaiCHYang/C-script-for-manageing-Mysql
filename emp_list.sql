start transaction;

create database demo_employee_list;

use demo_employee_list;

create table dept (
    Primary_dID int Primary key auto_increment,
    dept_no int unique,
    dept_name varchar(30) not null
);

insert into dept (dept_no, dept_name) values 
(1,'Marketing'),
(2,'accounting'),
(3,'Run_out_Of_Idear_:.(');

create table emp (
    Primary_eID int Primary key auto_increment,
    emp_no int unique default 00,
    emp_name varchar(50) not null,
    dept_no int,
    foreign key(dept_no) references dept(dept_no)
);

insert into emp (emp_no, emp_name, dept_no) values 
(001, 'Aydan', 1),
(002, 'Wang', 3),
(005, 'Jack', 2),
(069,'June', 1);

commit;