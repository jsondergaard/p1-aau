DROP TABLE assignments;
CREATE TABLE assignments (
	id integer PRIMARY KEY,
	title varchar NOT NULL,
	original_due_at date NOT NULL,
	due_at date NOT NULL,
	due_at_time time NOT NULL,
	student_time integer NOT NULL,
	created_at datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
	updated_at datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
 );

INSERT INTO "assignments" ("id", "title", "original_due_at", "due_at", "due_at_time", "student_time", "created_at", "updated_at") VALUES
('1', 'Test', '2021-12-24', '2021-12-24', '12:00', '10', '2021-12-14 09:21:01', '2021-12-14 09:21:01'),
('2', 'Test 2', '2021-12-26', '2021-12-26', '14:00', '5', '2021-12-14 09:21:47', '2021-12-14 09:21:47'),
('3', 'Test 3', '2021-12-24', '2021-12-24', '12:00', '48', '2021-12-14 09:21:47', '2021-12-14 09:21:47');