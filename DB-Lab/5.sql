SELECT studemt.sname, sc.GRADE FROM sc, student WHERE student.sno = sc.sno AND sc.cno = 'c4' ORDER BY sc.GRADE DESC; 
SELECT COUNT(*), Avg(age) FROM STUDENT;
SELECT sno, COUNT(*), AVG(GRADE) FROM sc GROUP BY sno; 
SELECT sno, AVG(GRADE) FROM sc GROUP BY sno HAVING AVG(GRADE) > 80;
SELECT sc.sno, student.sname, sc.grade FROM sc, student WHERE sc.sno = student.sno AND cno = (SELECT cno FROM COURSE WHERE CNAME = 'java');
SELECT  student.sno, course.cname, sc.grade FROM student, course, sc WHERE student.sno = sc.sno AND  course.cno = sc.cno;

SELECT SNO, SNAME, SEX, AGE, DEPF FROM student WHERE DEPT = '计算机系' UNION SELECT SNO, SNAME, SEX, AGE, DEPT FROM student WHERE DEPT = '日语系';
-- SELECT student.SNO, sc.CNO, student.DEPT FROM student, sc WHERE sc.sno = student.sno INTERSECT SELECT SNO FROM student WHERE DEPT = '管理系';
SELECT SNO FROM student WHERE DEPT = '信息系' INTERSECT SELECT SNO FROM sc WHERE CNO = 'c4';
SELECT SNO, SNAME, SEX, AGE, DEPT FROM STUDENT WHERE DEPT = '管理系' EXCEPT SELECT SNO, SNAME, SEX, AGE, SEPT FROM student WHERE AGE <= 20;