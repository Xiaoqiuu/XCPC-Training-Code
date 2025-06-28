CREATE TABLE student(
    sno CHAR(8) PRIMARY KEY,
    sname VARCHAR(20) NOT NULL,
    sex VARCHAR(10) CHECK(sex = '男' OR sex = '女'),
    age INT CHECK(age > 16),
    dept VARCHAR(10)
);

CREATE TABLE course(
    cno CHAR(8) PRIMARY KEY,
    cname VARCHAR(10) NOT NULL,
    tname VARCHAR(10),
    credit NUMBER
);

CREATE TABLE sc(
    sno CHAR(8) REFERENCES student(sno), 
    cno CHAR(8) REFERENCES course(cno),
    grade NUMBER,
    PRIMARY KEY(sno, cno)
);

ALTER TABLE course MODIFY cname CHAR(20);
UPDATE course SET credit = credit + 1;

SELECT sno, COUNT(*), AVG(grade) FROM sc GROUP BY sno;
SELECT sno, AVG(grade) FROM sc GROUP BY sno HAVING AVG(grade) > 75 ORDER BY AVG(grade) DESC;
SELECT sc.sname, course.cname, sc.grade FROM student, sc, course WHERE student.sno = sc.sno AND course.cno = sc.cno AND student.dept = '日语系';