all:
	make -C src/

report:
	pdflatex project_report.tex
	bibtex project_report
	bibtex project_report
	pdflatex project_report.tex
	pdflatex project_report.tex

clean:
	rm project_report.aux
	rm project_report.bbl
	rm project_report.blg
	rm project_report.log
