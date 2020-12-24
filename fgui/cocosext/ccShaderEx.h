#pragma once

static const char* HSV_CORLOR_MODE = "hsv_color";
static const char* HSV_HUE = "u_hue";
static const char* HSV_SATURATION = "u_saturation";
static const char* HSV_BRIGHTNESS = "u_brightness";
static const char* HSV_CONTRAST = "u_contrast";

static const char* ccPositionTextureColor_noMVP_hsv_frag = R"(
#ifdef GL_ES
precision lowp float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

uniform float u_hue;
uniform float u_saturation;
uniform float u_brightness;
uniform float u_contrast;

vec3 rgbtohsv(vec3 rgb)
{
	float R = rgb.x;
    float G = rgb.y;
    float B = rgb.z;
    vec3 hsv;
    float max1 = max(R, max(G, B));
    float min1 = min(R, min(G, B));
    if (R == max1)
    {
        hsv.x = (G - B) / (max1 - min1);
    }
    if (G == max1)
    {
        hsv.x = 2.0 + (B - R) / (max1 - min1);
    }
    if (B == max1)
    {
        hsv.x = 4.0 + (R - G) / (max1 - min1);
    }
    hsv.x = hsv.x * 60.0;
    if (hsv.x  < 0.0)
    {
        hsv.x = hsv.x + 360.0;
    }
    hsv.z = max1;
    hsv.y = (max1 - min1) / max1;
    return hsv;
}


vec3 hsvtorgb(vec3 hsv)
{
	float R;
	float G;
	float B;
	if (hsv.y == 0.0)
	{
		R = G = B = hsv.z;
	}
	else
	{
		hsv.x = hsv.x / 60.0;
		int i = int(hsv.x);
		float f = hsv.x - float(i);
		float a = hsv.z * (1.0 - hsv.y);
		float b = hsv.z * (1.0 - hsv.y * f);
		float c = hsv.z * (1.0 - hsv.y * (1.0 - f));
		if (i == 0)
		{
			R = hsv.z;
			G = c;
			B = a;
		}
		else if (i == 1)
		{
			R = b;
			G = hsv.z;
			B = a;
		}
		else if (i == 2)
		{
			R = a;
			G = hsv.z;
			B = c;
		}
		else if (i == 3)
		{
			R = a;
			G = b;
			B = hsv.z;
		}
		else if (i == 4)
		{
			R = c;
			G = a;
			B = hsv.z;
		}
		else
		{
			R = hsv.z;
			G = a;
			B = b;
		}
	}
	return vec3(R, G, B);
}

void main()
{
	vec4 pixColor = texture2D(CC_Texture0, v_texCoord);
	vec3 hsv;
	hsv.xyz = rgbtohsv(pixColor.xyz);
	hsv.x += u_hue * 180.0;
	if (hsv.x < 0){
		hsv.x += 360.0;
	}
	hsv.x = mod(hsv.x,360.0);
	hsv.y *= (1.0 + u_saturation);
	hsv.z *= (1.0 + u_brightness);
	vec3 f_color = hsvtorgb(hsv);
	f_color = ((f_color - 0.5) * max(u_contrast + 1.0, 0.0)) + 0.5;
	gl_FragColor = v_fragmentColor * vec4(f_color, pixColor.a);
}
)";


static const char* ccPositionTexture_GrayScale_frag = R"(
#ifdef GL_ES
precision mediump float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

void main(void)
{
    vec4 c = texture2D(CC_Texture0, v_texCoord);
     c = v_fragmentColor * c;
    gl_FragColor.xyz = vec3(0.2126*c.r + 0.7152*c.g + 0.0722*c.b);
    gl_FragColor.w = c.w;
}
)";

static const char* SHADER_NAME_POSITION_GRAYSCALE = "ShaderUIGrayScale";

void loadShaderEx();
