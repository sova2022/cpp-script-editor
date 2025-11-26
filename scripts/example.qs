   /**
    * API
    * canvas.clear();
    * canvas.line(double x1, double y1, double x2, double y2, const QString& color = "black");
    * canvas.rect(double x, double y, double w, double h, const QString& color = "black", 
    *	const QString& fillColor = "transparent");
    *
    * canvas.ellipse(double x, double y, double w, double h, const QString& color = "black", 
    *	const QString& fillColor = "transparent");
    *
    * canvas.triangle(double x1, double y1, double x2, double y2, double x3, double y3,  
    * 	const QString& color = "black", const QString& fillColor = "transparent");
    *
    */

canvas.clear();
canvas.line(10, 150, 200, 150);
canvas.line(10, 200, 200, 200, "blue");
canvas.line(10, 250, 200, 250, "red");
canvas.line(10, 300, 200, 300, "yellow");
canvas.rect(50, 50, 100, 80, "green", "green");
canvas.ellipse(300, 50, 100, 100, "turquoise");
canvas.ellipse(300, 200, 100, 100, "blue", "blue");
canvas.triangle(300, 420, 400, 420, 350, 350, "magenta", "magenta");