DROP TABLE assignments;
CREATE TABLE assignments (
	id integer PRIMARY KEY,
	title varchar NOT NULL,
	due_at datetime NOT NULL,
	buffer_time integer NOT NULL,
	student_time integer NOT NULL,
	created_at datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
	updated_at datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
 )

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