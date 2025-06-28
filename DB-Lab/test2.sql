CREATE TABLE dept(
    deptno CHAR(8) PRIMARY KEY,
    dname, VARCHAR(10) UNIQUE,
    loc, VARCHAR(10)
);

CREATE TABLE emp(
    empno CHAR(8) PRIMARY KEY, 
    ename VARCHAR(20) NOT NULL,
    age INT CHECK(age >= 18 AND age <= 55),
    sal NUMBER CHECK(sal > 1200)， 
    deptno CHAR(8) REFERENCES dept(deptno)
);

ALTER TABLE emp ADD sex VARCHAR(10);
SELECT ename, sal * 12 FROM emp WHERE age >= 20 AND age <= 30;
SELECT ename, age FROM emp WHERE ename LIKE '李%';
SELECT COUNT(*), AVG(sal) FROM emp GROUP BY deptno HAVING AVG(age) > 45 ORDER BY AVG(age) ASC, COUNT(*) DESC;
-- CREATE VIEW emp_fin (
--     deptno, loc, empno, ename, sal
-- );
CREATE VIEW emp_fin AS
SELECT emp.deptno, dept.loc, emp.empno, emp.ename, emp.sal
FROM emp
JOIN dept ON emp.deptno = dept.deptno
WHERE dept.dname = '财务部';