biferror.png: bifurcation_plot.py
	python bifurcation_plot.py
    
bifnuevo.png: bifurcationcorrect_plot.py
	python bifurcationcorrect_plot.py

clean:
	rm -rf bifnuevo.png biferror.png