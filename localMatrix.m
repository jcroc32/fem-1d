function [A0_local,A1_local,A2_local,cubicHermite] = localMatrix(h)
	% f_1(x), f_2,(x), f_3(x), f_4(n) is element we are using on mesh
	% f_i(x) = a_i*x^3 + b_i*x^2 + c_i*x + d_i, on [-1, 1]
	% f_i'(x) = 3a_i*x^2 + 2b_i*x + c, on [-1, 1]
	
	% f_1(-1)  = 1,    f_1'(-1) = f_1 (1)  = f_1'(1) = 0
	% f_2'(-1) = 1,    f_2(-1)  = f_2 (1)  = f_2'(1) = 0
	% f_3(1)   = 1,    f_3(-1)  = f_3'(-1) = f_3'(1) = 0
	% f_4'(1)  = 1,    f_4'(-1) = f_4'(-1) = f_4 (1) = 0
	
	
	
	% [ f(-1)  f'(-1)  f(1)  f'(1) ]
	F = [-1      3      1      3;  % [  a
		  1     -2      1      2;  %	b
		 -1      1      1      1;  %	c
		  1      0      1      0]; %	d  ];
	
	% F * element = I
	cubicHermite = F\eye(size(F)).*[1; h/2; 1; h/2];
	% derivative
	cubicHermite1 = polyDerivative(cubicHermite);
	% second derivative
	cubicHermite2 = polyDerivative(cubicHermite1);

	% check what basis looks like
	% x = transpose(-1:.1:1);
	% X = [x.^3 x.^2 x ones(size(x))];
	% figure()
	% plot(x,X*cubicHermite0)


	A0_local = zeros(4);
	A1_local = zeros(4);
	A2_local = zeros(4);

	for n = 1:4
		A0_local(n,:) = gaussQuad(conv2(cubicHermite,cubicHermite(n,:)));
	end

	for n = 1:4
		A1_local(n,:) = gaussQuad(conv2(cubicHermite1,cubicHermite1(n,:)));
	end

	for n = 1:4
		A2_local(n,:) = gaussQuad(conv2(cubicHermite2,cubicHermite2(n,:)));
	end

	jacobian = h/2;
	jacobian1 = 2/h;
	jacobian2 = 8/h^3;

	A0_local = jacobian*A0_local;
	A1_local = jacobian1*A1_local;
	A2_local = jacobian2*A2_local;
end

function v = polyDerivative(v) 
v = v.*(length(v(1,:))-1:-1:0);
v(:,end) = [];
end

function v = gaussQuad(f) % from -1 to 1
 % Gaussian quad, exact for deg 7 and below
weight = [0.3478548451374538;
          0.6521451548625461;
          0.6521451548625461;
          0.3478548451374538];

x = [-0.8611363115940526, -0.3399810435848563, 0.3399810435848563, 0.8611363115940526];

if isa(f, 'function_handle')
    v = f(x)*weight;

elseif isa(f, 'numeric') % if representing polynomial with row vector
    X = zeros(length(f(1,:)),length(x));
    X(end,:) = ones(size(x));
    for n = 1:length(f(1,:))-1
        X(end-n,:) = x.^n;
    end
    v = f*X*weight;
end
end