SELECT studemt.sname, sc.GRADE FROM sc, student WHERE student.sno = sc.sno AND sc.cno = 'c4' ORDER BY sc.GRADE DESC; 
SELECT COUNT(*), Avg(age) FROM STUDENT;
SELECT sno, COUNT(*), AVG(GRADE) FROM sc GROUP BY sno; 
SELECT sno, AVG(GRADE) FROM sc GROUP BY sno HAVING AVG(GRADE) > 80;
SELECT sc.sno, student.sname, sc.grade FROM sc, student WHERE sc.sno = student.sno AND cno = (SELECT cno FROM COURSE WHERE CNAME = 'java');
SELECT  student.sno, course.cname, sc.grade FROM student, course, sc WHERE student.sno = sc.sno AND  course.cno = sc.cno;