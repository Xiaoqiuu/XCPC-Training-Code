CREATE TABLE EMPLOYEES (
    ENO CHAR(8) PRIMARY KEY,
    ENAME VARCHAR2(10) NOT NULL,
    SEX CHAR(6) CHECK(sex IN ('男', '女')),
    AGE INT CHECK(age > 18),
    JOB VARCHAR2(20),
    SAL NUMBER,
    DEPT VARCHAR2(20)
);

INSERT INTO EMPLOYEES VALUES (1001, '张三', '男', 20, '销售', 1000, '市场部');
INSERT INTO EMPLOYEES VALUES (1002, '李四', '女', 26, '会计', 1600, '财务部');
INSERT INTO EMPLOYEES VALUES (1003, '王五', '女', 22, '销售', 1000, '市场部');
INSERT INTO EMPLOYEES VALUES (1004, '赵六', '男', 19, NULL, NULL, NULL);
INSERT INTO EMPLOYEES VALUES (1005, '张七', '女', 23, '测试', 1400, '技术部');
INSERT INTO EMPLOYEES VALUES (1006, '赵八', '男', 30, '研发', 2000, '技术部');

SELECT ENAME, SEX, SAL FROM EMPLOYEES;
SELECT DISTINCT DEPT FROM EMPLOYEES WHERE EMPLOYEES;
SELECT ENAME, 2025-AGE FROM EMPLOYEES;
SELECT ENAME, AGE FROM EMPLOYEES WHERE SAL > 1200;
SELECT ENAME, SAL FROM EMPLOYEES WHERE AGE < 20 OR AGE > 25;
SELECT ENAME, SEX FROM EMPLOYEES WHERE DEPT IN ('财务部', '技术部');
SELECT ENAME, AGE, JOB FROM EMPLOYEES WHERE ENAME LIKE '张%';
SELECT ENAME, AGE FROM EMPLOYEES WHERE JOB IS NULL;
SELECT ENAME, SAL FROM EMPLOYEES WHERE AGE > 20 ORDER BY SAL DESC;
SELECT COUNT(*) FROM EMPLOYEES WHERE DEPT = '市场部';
SELECT MAX(SAL) FROM EMPLOYEES;
SELECT MIN(SAL) FROM EMPLOYEES;
SELECT AVG(AGE) FROM EMPLOYEES;
SELECT SUM(SAL) FROM EMPLOYEES WHERE DEPT = '市场部'; 