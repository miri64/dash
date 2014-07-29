all:
	make -C src/

report:
	pdflatex project_report.tex
	bibtex project_report
	bibtex project_report
	pdflatex project_report.tex
	pdflatex project_report.tex
