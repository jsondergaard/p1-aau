DROP TABLE IF EXISTS assignments;
CREATE TABLE assignments (
  id int(11) NOT NULL,
  title varchar(128) NOT NULL,
  due_at date NOT NULL,
  buffer_time int(11) NOT NULL,
  student_time int(11) NOT NULL,
  created_at date NOT NULL DEFAULT (datetime('now','localtime')),
  updated_at date NOT NULL DEFAULT (datetime('now','localtime')),
  PRIMARY KEY (id))

--Create before update and after insert triggers:
-- CREATE TRIGGER UPDATE_ASSIGNMENTS BEFORE UPDATE ON assignments
--     BEGIN
--        UPDATE assignments SET updated_at = datetime('now', 'localtime')
--        WHERE rowid = new.rowid;
--     END

-- CREATE TRIGGER INSERT_ASSIGNMENTS AFTER INSERT ON assignments
--     BEGIN
--        UPDATE assignments SET created_at = datetime('now', 'localtime')
--        WHERE rowid = new.rowid;
--     END