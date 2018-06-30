// Copyright 2016 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "MagickaVoxelActor.generated.h"

class UVoxelComponent;

UCLASS()
class VOX4U_API AMagickaVoxelActor : public AActor
{
	GENERATED_BODY()

	AMagickaVoxelActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:

	UVoxelComponent* GetVoxelComponent() const;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = VoxelActor)
	UVoxelComponent* VoxelComponent;

};
