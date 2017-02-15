using UnityEngine;
using System.Collections;

public class RotationManager : MonoBehaviour {

	//Update is called every frame
	void Update () 
	{
		transform.Rotate (new Vector3 (0, 0, 45) * Time.deltaTime);
	}
}
