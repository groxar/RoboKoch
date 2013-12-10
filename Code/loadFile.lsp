; Einsammeln von Ausdr�cken aus einer Datei

(defvar *extfile*)

(setq *extfile* nil)

(DEFUN LOAD_extfile (Dateiname)
	(LET ((STREAM (OPEN Dateiname :DIRECTION :INPUT)))
		(DO ((Ausdruck NIL (READ STREAM NIL STREAM)))
		((EQ Ausdruck STREAM) (CLOSE STREAM))
		(setq *extfile* (cons Ausdruck *extfile*)))))

; diese liegen anschlie�end in einer Liste zusammengefasst in der Variable *extfile*
